import pandas as pd
import numpy as np
from sklearn.ensemble import GradientBoostingRegressor
import shap
import seaborn as sns
from matplotlib import pyplot as plt
from numpy import loadtxt
from urllib.request import urlopen
import missingno as msno
from matplotlib import font_manager, rc
import mglearn
import matplotlib.patches as mpatches
import lime
import lime.lime_tabular
from sklearn.model_selection import train_test_split, KFold, cross_val_score, cross_validate
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import mean_squared_error, make_scorer, r2_score, mean_absolute_error, median_absolute_error, explained_variance_score

plt.rcParams['font.family'] = 'Malgun Gothic' # matplotlib 한글패치

# 데이터 로드
df = pd.read_csv('./한국전력거래소_일별 화력발전량/최종/최최종데이터.csv')

# NaN 값을 0으로 치환
df.fillna(0, inplace=True)

# x, y 데이터 분리
x = df.drop(columns=['천식 발생률(%)', '눈병 발생률(%)', '피부염 발생률(%)', '감기 발생률(%)', '위도_x', '경도_x', '월_sin', '요일', '시군구', '관리관서', '이전날짜차이'])
y = df['천식 발생률(%)']


# train test 분리
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state=42)

# Gradient Boosting 모델 초기화
GBM_model = GradientBoostingRegressor(n_estimators=100, max_depth=10, random_state=42)

# 모델 학습
GBM_model.fit(x_train, y_train)

#-------------------------------------------------------------------------------------

# 예측
gbm_predicted_value = GBM_model.predict(x_test)

# 실제 값과 예측 값 비교를 위한 데이터프레임 생성
comparison_df = pd.DataFrame({'Actual value': y_test, 'Predicted value': gbm_predicted_value})

# 실제 값과 예측 값 비교 그래프

plt.figure(figsize=(10, 6))
plt.plot(comparison_df.index, comparison_df['Actual value'], marker='o', linestyle='-', label='Actual value')
plt.plot(comparison_df.index, comparison_df['Predicted value'], marker='o', linestyle='-', label='Predicted value')
plt.title('Actual vs Predicted value(천식 발생률(%))')
plt.xlabel('Index')
plt.ylabel('Value')
plt.legend()
plt.grid(True)
plt.show()

#-------------------------------------------------------------------------------------

# KFold 설정
k = 5
kf = KFold(n_splits=k, shuffle=True, random_state=42)

# RMSE를 사용한 교차 검증 점수 계산
rmse_scorer = make_scorer(mean_squared_error, squared=False)
cv_scores = cross_val_score(GBM_model, x, y, cv=kf, scoring=rmse_scorer)

print(f"교차검증 RMSE scores: {cv_scores}")
print(f"RMSE 평균: {np.mean(cv_scores)}")
print(f"RMSE 표준편차: {np.std(cv_scores)}")

# 평가
rmse_variable = mean_squared_error(y_test, gbm_predicted_value, squared=False)
print("천식 발생률(%) 예측 RMSE:", rmse_variable)

# MAPE 계산 함수
def calculate_mape(y_true, gbm_predicted_value):
    if (gbm_predicted_value == 0).any():
        raise ValueError("0 error")
    absolute_percentage_errors = np.abs((y_true - gbm_predicted_value) / y_true)
    mape = np.mean(absolute_percentage_errors) * 100
    return mape

# 예측값과 실제값을 사용하여 MAPE 계산
gbm_mape = calculate_mape(y_test, gbm_predicted_value)
print("GBM MAPE:", gbm_mape)

# 평가 지표 계산
rmse = np.sqrt(mean_squared_error(y_test, gbm_predicted_value))
r2 = r2_score(y_test, gbm_predicted_value)
mae = mean_absolute_error(y_test, gbm_predicted_value)
mse = mean_squared_error(y_test, gbm_predicted_value)
medae = median_absolute_error(y_test, gbm_predicted_value)
evs = explained_variance_score(y_test, gbm_predicted_value)

# Adjusted R² 계산
n = len(y_test)
p = x_test.shape[1]
adjusted_r2 = 1 - ((1 - r2) * (n - 1) / (n - p - 1))

# 결과 출력
print(f"RMSE: {rmse}")
print(f"R²: {r2}")
print(f"MAE: {mae}")
print(f"MSE: {mse}")
print(f"MedAE: {medae}")
print(f"EVS: {evs}")
print(f"Adjusted R²: {adjusted_r2}")


#-------------------------------------------------------------------------------------

# LIME 적용
explainer = lime.lime_tabular.LimeTabularExplainer(x_train.values, feature_names=x.columns, class_names=['천식 발생률(%)'], mode='regression')
i = 0  # 첫 번째 샘플에 대해 설명
exp = explainer.explain_instance(x_test.iloc[i].values, GBM_model.predict, num_features=5)
exp.show_in_notebook(show_table=True)

# 설명 결과 추출
lime_result = exp.as_list()
predicted_value = exp.predicted_value

# 설명 결과를 데이터프레임으로 변환
lime_df = pd.DataFrame(lime_result, columns=['Feature', 'Contribution'])
# lime_df['Feature Value'] = [x_test.iloc[i][feature] for feature, _ in lime_result]  # 기존 코드 주석 처리
lime_df['Feature Value'] = [feature.split(' ')[-1] for feature, _ in lime_result]  # 수정된 코드

# 긍정적, 부정적 기여도 구분
lime_df['Contribution Type'] = lime_df['Contribution'].apply(lambda x: 'positive' if x > 0 else 'negative')

# 시각화
plt.figure(figsize=(10, 6))
sns.barplot(x='Contribution', y='Feature', hue='Contribution Type', dodge=False, data=lime_df, palette={'positive': 'blue', 'negative': 'red'})
plt.title(f'LIME Explanation for Sample {i} (Predicted value: {predicted_value})(천식 발생률(%))')
plt.xlabel('Contribution to Prediction')
plt.ylabel('Feature')

# Feature Value 추가
for index, row in lime_df.iterrows():
    plt.text(row['Contribution'], index, f' ({row["Feature Value"]})', color='black', va="center")

plt.show()

#-------------------------------------------------------------------------------------

# SHAP 설명자 생성
shap.initjs()
explainer = shap.TreeExplainer(GBM_model, x_train)
shap_values = explainer(x_test, check_additivity=False)

# 첫 번째 샘플에 대해 SHAP 값 시각화
shap.plots.waterfall(shap_values[0])
 # SHAP summary plot
shap.summary_plot(shap_values, x_test)

