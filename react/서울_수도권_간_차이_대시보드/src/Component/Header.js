import React from "react";
import "../Styles/Header.css";

const Header = ({ isSwitchOn }) => {
  return (
    <div className="header-container">
      <p className="header-text">
        {isSwitchOn ? "지방 활성화를 통한 해결" : "수도권 인구 밀집의 심화"}
      </p>
    </div>
  );
};

export default Header;
