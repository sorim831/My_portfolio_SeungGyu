import React from "react";
import "../Styles/Main.css";

import Traffic from "./Traffic";
import House from "./House";
import Environment from "./Environment";
import InflowChart from "./InflowChart";
import OutflowChart from "./OutflowChart";

function Capital() {
  return (
    <div style={{ display: "flex" }}>
      <div className="Seoul-population">
        이 자리에 서울 인구 그래프
        <InflowChart />
        <hr style={{ width: "90%", margin: "10px auto" }} />
        <OutflowChart />
        <hr style={{ width: "90%", margin: "10px auto" }} />
      </div>
      <div className="capital-container">
        Capital
        <Traffic />
        <hr style={{ width: "90%", margin: "10px auto" }} />
        <House />
        <hr style={{ width: "90%", margin: "10px auto" }} />
        <Environment />
      </div>
      <div className="Seoul-population">이 자리에 수도권 인구 그래프</div>
    </div>
  );
}

export default Capital;
