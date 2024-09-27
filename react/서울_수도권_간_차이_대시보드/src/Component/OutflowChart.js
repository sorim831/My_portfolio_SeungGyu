// src/components/OutflowChart.js
import React from "react";
import { Pie } from "react-chartjs-2";
import { Chart as ChartJS, ArcElement, Tooltip, Legend } from "chart.js";

ChartJS.register(ArcElement, Tooltip, Legend);

const OutflowChart = () => {
  const totalCapitalOutflow = 31.4; // 수도권 전출 비율
  const totalNonCapitalOutflow = 68.6; // 비수도권 전출 비율

  const data = {
    labels: ["수도권 전출", "비수도권 전출"],
    datasets: [
      {
        label: "전출 비율",
        data: [totalCapitalOutflow, totalNonCapitalOutflow],
        backgroundColor: ["blue", "orange"],
        hoverOffset: 4,
      },
    ],
  };

  const options = {
    responsive: true,
    plugins: {
      legend: {
        position: "top",
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
      text: "2023년 수도권과 비수도권 전출 비율",
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

export default OutflowChart;
