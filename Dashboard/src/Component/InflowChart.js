// src/components/InflowChart.js
import React from "react";
import { Pie } from "react-chartjs-2";
import { Chart as ChartJS, ArcElement, Tooltip, Legend } from "chart.js";

ChartJS.register(ArcElement, Tooltip, Legend);

const InflowChart = () => {
  // 수도권과 비수도권의 비율 (파이썬에서 계산된 비율 사용)
  const totalCapitalInflow = 78.5; // 수도권 전입 비율
  const totalNonCapitalInflow = 21.5; // 비수도권 전입 비율

  // Chart.js에서 사용할 데이터
  const data = {
    labels: ["수도권 전입", "비수도권 전입"], // 각 섹션에 대한 라벨
    datasets: [
      {
        label: "전입 비율",
        data: [totalCapitalInflow, totalNonCapitalInflow], // 비율 데이터
        backgroundColor: ["blue", "orange"], // 각 섹션의 색상
        hoverOffset: 4, // 마우스 호버 시 섹션이 튀어나오는 정도
      },
    ],
  };

  // 차트 옵션
  const options = {
    responsive: true,
    plugins: {
      legend: {
        position: "top", // 범례를 상단에 위치
      },
      tooltip: {
        callbacks: {
          label: function (tooltipItem) {
            const total = tooltipItem.dataset.data.reduce((a, b) => a + b, 0);
            const currentValue = tooltipItem.raw;
            const percentage = ((currentValue / total) * 100).toFixed(1);
            return `${tooltipItem.label}: ${percentage}%`;
          },
        },
      },
    },
    title: {
      display: true,
      text: "2023년 수도권과 비수도권 전입 비율",
      font: {
        size: 16,
      },
    },
  };

  return (
    <div style={{ width: "50%", margin: "auto" }}>
      <Pie data={data} options={options} />
    </div>
  );
};

export default InflowChart;
