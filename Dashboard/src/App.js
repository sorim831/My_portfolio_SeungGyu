import "./App.css";
import Main from "./Component/Main";
import Header from "./Component/Header";
import Switch from "./Component/Switch";

import React, { useState } from "react";

function App() {
  const [isSwitchOn, setIsSwitchOn] = useState(false);

  const toggleSwitch = () => {
    setIsSwitchOn(!isSwitchOn);
  };

  return (
    <div className="App">
      <Header isSwitchOn={isSwitchOn} />
      <Switch isSwitchOn={isSwitchOn} toggleSwitch={toggleSwitch} />
      <Main isSwitchOn={isSwitchOn} />
    </div>
  );
}

export default App;
