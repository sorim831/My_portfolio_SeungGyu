import React from "react";
import { Bar } from "react-chartjs-2";
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

function House() {
  const data = {
    labels: ["서울", "지방"],
    datasets: [
      {
        data: [93.7, 107.5],
        backgroundColor: "rgba(75, 112, 192, 0.5)",
        barThickness: 50,
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
        text: "2022년도 서울 / 지방 주택공급률(%) 비교",
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

export default House;
