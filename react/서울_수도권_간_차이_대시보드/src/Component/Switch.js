// Switch.js
import React from "react";
import "../Styles/Switch.css";

const Switch = ({ isSwitchOn, toggleSwitch }) => {
  return (
    <label className="switch">
      <input type="checkbox" checked={isSwitchOn} onChange={toggleSwitch} />
      <span className="slider"></span>
    </label>
  );
};

export default Switch;
