import React from "react";
import { Bar } from "react-chartjs-2";
import "chart.js/auto";
import "../Styles/Main.css";

function CityPark() {
  const data = {
    labels: [
      "전국",
      "서울특별시",
      "부산광역시",
      "대구광역시",
      "인천광역시",
      "광주광역시",
      "대전광역시",
      "울산광역시",
      "세종특별자치시",
      "경기도",
      "강원특별자치도",
      "충청북도",
      "충청남도",
      "전북특별자치도",
      "전라남도",
      "경상북도",
      "경상남도",
      "제주특별자치도",
    ],
    datasets: [
      {
        label: "인구천명당 도시공원조성면적 (천㎡)",
        data: [
          12.6, 4.6, 17.5, 9.6, 14.1, 13.3, 13.0, 10.4, 62.8, 11.2, 16.1, 16.1,
          11.5, 24.5, 26.2, 16.6, 16.0, 16.7,
        ],
        borderColor: [
          "#4A90E2",
          "#E74C3C",
          "#D0021B",
          "#9B59B6",
          "#4A90E2",
          "#D0021B",
          "#F39C12",
          "#2ECC71",
          "#F1C40F",
          "#8E44AD",
          "#E67E22",
          "#2980B9",
          "#16A085",
          "#F39C12",
          "#E74C3C",
          "#7ED321",
          "#34495E",
          "#2C3E50",
        ],
        backgroundColor: [
          "#4A90E2",
          "#E74C3C",
          "#D0021B",
          "#9B59B6",
          "#4A90E2",
          "#D0021B",
          "#F39C12",
          "#2ECC71",
          "#F1C40F",
          "#8E44AD",
          "#E67E22",
          "#2980B9",
          "#16A085",
          "#F39C12",
          "#E74C3C",
          "#7ED321",
          "#34495E",
          "#2C3E50",
        ],
      },
    ],
  };

  const options = {
    scales: {
      y: {
        beginAtZero: true,
        title: {
          display: true,
          text: "도시공원조성면적 (천㎡)",
        },
      },
    },
    plugins: {
      legend: {
        position: "top",
      },
      title: {
        display: true,
        text: "행정구역별 인구천명당 도시공원조성면적",
      },
    },
  };

  return (
    <div className="dashboard">
      <Bar data={data} options={options} className="city-parks-chart" />
    </div>
  );
}

export default CityPark;
