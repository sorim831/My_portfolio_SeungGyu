import React from "react";
import "../Styles/Main.css";

import Capital from "./Capital";
import Province from "./Province";

const Main = ({ isSwitchOn }) => {
  return <div>{isSwitchOn ? <Province /> : <Capital />}</div>;
};

export default Main;
