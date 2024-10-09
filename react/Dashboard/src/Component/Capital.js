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
        <InflowChart />
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
      <div className="Seoul-population">
        <OutflowChart />
        <hr style={{ width: "90%", margin: "10px auto" }} />
      </div>
    </div>
  );
}

export default Capital;
