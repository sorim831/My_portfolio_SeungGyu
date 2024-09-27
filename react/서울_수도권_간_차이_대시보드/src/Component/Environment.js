import React from "react";
import { Line } from "react-chartjs-2";
import {
  Chart as ChartJS,
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
  Title,
  Tooltip,
  Legend,
} from "chart.js";

ChartJS.register(
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
  Title,
  Tooltip,
  Legend
);

function Environment() {
  const data = {
    labels: ["2013", "2015", "2017", "2019", "2021", "2023"], //년도 (2년 간격)
    datasets: [
      {
        label: "미세먼지 주의보 횟수",
        data: [1, 3, 6, 8, 8, 10],
        borderColor: "rgba(75, 192, 192, 1)",
        backgroundColor: "rgba(75, 192, 192, 0.2)",
        fill: true,
        tension: 0,
      },
      {
        label: "오존 주의보 횟수",
        data: [18, 4, 33, 29, 32, 45],
        borderColor: "rgba(255, 99, 132, 1)",
        backgroundColor: "rgba(255, 99, 132, 0.2)",
        fill: true,
        tension: 0,
      },
    ],
  };

  const options = {
    responsive: true,
    plugins: {
      legend: {
        position: "top",
      },
      title: {
        display: true,
        text: "년도별 미세먼지 주의보 및 경보 일수",
      },
    },
    scales: {
      y: {
        beginAtZero: true,
        title: {
          display: true,
          text: "일수",
        },
      },
    },
  };

  return (
    <Line
      data={data}
      options={options}
      style={{ width: "90%", margin: "auto" }}
    />
  );
}

export default Environment;
