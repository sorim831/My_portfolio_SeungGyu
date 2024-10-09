import { render, screen } from "@testing-library/react";
import App from "./App";

test("renders learn react link", () => {
  render(<App />);
  const linkElement = screen.getByText(/learn react/i);
  expect(linkElement).toBeInTheDocument();
});

/*
import React, { Component } from "react";
import TOC from "./components/TOC";
import Content from "./components/Content";
import Subject from "./components/Subject";
import "./App.css";

class App extends Component {
  render() {
    return (
      <div className="App">
        <Subject title="WEB" sub="world wide web"></Subject>
        <TOC></TOC>
        <Content
          title="HTML"
          desc="HTML은 하이퍼텍스트 마크업 언어입니다람쥐."
        ></Content>
        <Content title="CSS" desc="CSS는 안써."></Content>
      </div>
    );
  }
}

export default App;

*/
