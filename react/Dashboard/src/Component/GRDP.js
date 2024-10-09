import React from "react";
import { Bar } from "react-chartjs-2";
import "chart.js/auto";
import "../Styles/Main.css";

function GRDP() {
  const data = {
    labels: ["2022년"],
    datasets: [
      {
        label: "인천광역시",
        data: [6],
        borderColor: "#4A90E2",
        backgroundColor: "#4A90E2",
      },
      {
        label: "경상남도",
        data: [4.6],
        borderColor: "#D0021B",
        backgroundColor: "#D0021B",
      },
      {
        label: "제주특별자치도",
        data: [4.6],
        borderColor: "#7ED321",
        backgroundColor: "#7ED321",
      },
      {
        label: "대전광역시",
        data: [4.5],
        borderColor: "#F39C12",
        backgroundColor: "#F39C12",
      },
      {
        label: "충청북도",
        data: [4.5],
        borderColor: "#8E44AD",
        backgroundColor: "#8E44AD",
      },
      {
        label: "경기도",
        data: [3.6],
        borderColor: "#3498DB",
        backgroundColor: "#3498DB",
      },
      {
        label: "세종특별자치시",
        data: [3.3],
        borderColor: "#F1C40F",
        backgroundColor: "#F1C40F",
      },

      {
        label: "강원특별자치도",
        data: [3.3],
        borderColor: "#2ECC71",
        backgroundColor: "#2ECC71",
      },
      {
        label: "부산광역시",
        data: [2.6],
        borderColor: "#E67E22",
        backgroundColor: "#E67E22",
      },
      {
        label: "충청남도",
        data: [2.5],
        borderColor: "#E74C3C",
        backgroundColor: "#E74C3C",
      },
      {
        label: "전라북도",
        data: [2.1],
        borderColor: "#9B59B6",
        backgroundColor: "#9B59B6",
      },
      {
        label: "대구광역시",
        data: [1.7],
        borderColor: "#34495E",
        backgroundColor: "#34495E",
      },

      {
        label: "광주광역시",
        data: [1.7],
        borderColor: "#16A085",
        backgroundColor: "#16A085",
      },
      {
        label: "경상북도",
        data: [1.7],
        borderColor: "#2980B9",
        backgroundColor: "#2980B9",
      },
      {
        label: "서울특별시",
        data: [1.6],
        borderColor: "#E74C3C",
        backgroundColor: "#E74C3C",
      },

      {
        label: "울산광역시",
        data: [-0.5],
        borderColor: "#2C3E50",
        backgroundColor: "#2C3E50",
      },

      {
        label: "전라남도",
        data: [-1.9],
        borderColor: "#F39C12",
        backgroundColor: "#F39C12",
      },
    ],
  };

  const options = {
    scales: {
      y: {
        beginAtZero: true,
      },
    },
    plugins: {
      legend: {
        position: "top",
      },
      title: {
        display: true,
        text: "지방지역내총생산",
      },
    },
  };

  return (
    <div className="dashboard">
      <Bar data={data} options={options} className="grgp" />
    </div>
  );
}

export default GRDP;
