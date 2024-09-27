import React from "react";
import { Bar } from "react-chartjs-2";
import {
  Chart as ChartJS,
  CategoryScale,
  LinearScale,
  BarElement,
  Title,
  Tooltip,
  Legend,
} from "chart.js";

// Chart.js의 각 컴포넌트를 등록합니다.
ChartJS.register(
  CategoryScale,
  LinearScale,
  BarElement,
  Title,
  Tooltip,
  Legend
);

function Traffic() {
  const data = {
    labels: [
      "2015",
      "2016",
      "2017",
      "2018",
      "2019",
      "2020",
      "2021",
      "2022",
      "2023",
    ],
    datasets: [
      {
        data: [
          8563, 8519, 10475, 10160, 10586, 10091, 10091, 9931, 10188, 10265,
        ],
        backgroundColor: "rgba(75, 192, 192, 0.5)",
      },
    ],
  };

  const options = {
    responsive: true,
    plugins: {
      legend: {
        position: "top",
        display: false,
      },
      title: {
        display: true,
        text: "(서울시) 9년간의 일평균 교통량",
      },
    },
  };

  return (
    <Bar
      data={data}
      options={options}
      style={{ width: "90%", margin: "auto" }}
    />
  );
}

export default Traffic;
