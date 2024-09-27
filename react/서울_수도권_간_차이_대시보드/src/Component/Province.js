import React from "react";
import "../Styles/Main.css";

import GRDP from "./GRDP";

function Province() {
  return (
    <div style={{ display: "flex" }}>
      <GRDP></GRDP>
      <div className="province-container">이 자리에 지방 인프라 그래프</div>
    </div>
  );
}

export default Province;
