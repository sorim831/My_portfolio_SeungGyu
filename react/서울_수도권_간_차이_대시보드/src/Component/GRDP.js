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
        borderColor: "#AFFFEE",
        backgroundColor: "#AFFFEE",
      },
      {
        label: "경상남도",
        data: [4.6],
        borderColor: "#FF5A5A	",
        backgroundColor: "#FF5A5A	",
      },
      {
        label: "제주특별자치도",
        data: [4.6],
        borderColor: "green",
        backgroundColor: "green",
      },
      {
        label: "대전광역시",
        data: [4.5],
        borderColor: "brown",
        backgroundColor: "brown",
      },
      {
        label: "충청북도",
        data: [4.5],
        borderColor: "#FDE1B4",
        backgroundColor: "#FDE1B4",
      },
      {
        label: "경기도",
        data: [3.6],
        borderColor: "#E478E4",
        backgroundColor: "#E478E4",
      },
      {
        label: "세종특별자치시",
        data: [3.3],
        borderColor: "orange",
        backgroundColor: "orange",
      },

      {
        label: "강원특별자치도",
        data: [3.3],
        borderColor: "#906D3B	",
        backgroundColor: "#906D3B	",
      },
      {
        label: "부산광역시",
        data: [2.6],
        borderColor: "yellow",
        backgroundColor: "yellow",
      },
      {
        label: "충청남도",
        data: [2.5],
        borderColor: "#A36464	",
        backgroundColor: "#A36464	",
      },
      {
        label: "전라북도",
        data: [2.1],
        borderColor: "#FFB6C1",
        backgroundColor: "#FFB6C1",
      },
      {
        label: "대구광역시",
        data: [1.7],
        borderColor: "#7AD7BE",
        backgroundColor: "#7AD7BE",
      },

      {
        label: "광주광역시",
        data: [1.7],
        borderColor: "purple",
        backgroundColor: "purple",
      },
      {
        label: "경상북도",
        data: [1.7],
        borderColor: "	#A297BD",
        backgroundColor: "	#A297BD",
      },
      {
        label: "서울특별시",
        data: [1.6],
        borderColor: "blue",
        backgroundColor: "blue",
      },

      {
        label: "울산광역시",
        data: [-0.5],
        borderColor: "#FFE3EE",
        backgroundColor: "#FFE3EE",
      },

      {
        label: "전라남도",
        data: [-1.9],
        borderColor: "#FAFAD2	",
        backgroundColor: "#FAFAD2	",
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
