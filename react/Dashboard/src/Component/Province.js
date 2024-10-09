import React from "react";
import "../Styles/Main.css";

import GRDP from "./GRDP";
import CityPark from "./CityPark";

function Province() {
  return (
    <div style={{ display: "flex" }}>
      <GRDP></GRDP>
      <div className="province-container">
        <CityPark />
      </div>
    </div>
  );
}

export default Province;
