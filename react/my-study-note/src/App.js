import React, { Component } from "react";
import { BrowserRouter as Router, Route, Routes } from "react-router-dom"; // Routes 추가
import TOC from "./components/TOC";
import ReadContent from "./components/ReadContent";
import Subject from "./components/Subject";
import Control from "./components/Control";
import CreateContent from "./components/CreateContent";
import UpdateContent from "./components/UpdateContent";
import MarkdownViewerWrapper from "./components/MarkdownViewer"; // MarkdownViewer 추가
import "./App.css";

class App extends Component {
  constructor(props) {
    super(props);
    this.max_content_id = 3;
    this.state = {
      mode: "welcome",
      selected_content_id: 2,
      subject: { title: "공부 노트", sub: "Made by Song Seung Gyu" },
      welcome: { title: "Welcome", desc: "Hello, React and Nodejs" },
      contents: [
        {
          id: 1,
          title: "React",
          category: "react",
          files: [
            "1주차.md",
            "2주차.md",
            "3주차.md",
            "4주차.md",
            "5주차.md",
            "6주차.md",
            "7주차.md",
            "8주차.md",
          ],
        },
        {
          id: 2,
          title: "NodeJS",
          category: "nodejs",
          files: [
            "1주차.md",
            "2주차.md",
            "3주차.md",
            "4주차.md",
            "5주차.md",
            "6주차.md",
            "7주차.md",
            "8주차.md",
          ],
        },
      ],
    };
  }

  getReadContent() {
    for (let i = 0; i < this.state.contents.length; i++) {
      const data = this.state.contents[i];
      if (data.id === this.state.selected_content_id) {
        return data;
      }
    }
    return null;
  }

  getContent() {
    let _article = null;

    if (this.state.mode === "welcome") {
      const { title, desc } = this.state.welcome;
      _article = <ReadContent title={title} desc={desc}></ReadContent>;
    } else if (this.state.mode === "read") {
      const _content = this.getReadContent();
      if (_content) {
        _article = (
          <ReadContent
            title={_content.title}
            desc={_content.desc}
          ></ReadContent>
        );
      }
    } else if (this.state.mode === "create") {
      _article = (
        <CreateContent
          onSubmit={function (_title, _desc) {
            this.max_content_id = this.max_content_id + 1;
            const _contents = Array.from(this.state.contents);
            _contents.push({
              id: this.max_content_id,
              title: _title,
              desc: _desc,
            });
            this.setState({
              contents: _contents,
              mode: "read",
              selected_content_id: this.max_content_id,
            });
            console.log(_title, _desc);
          }.bind(this)}
        ></CreateContent>
      );
    } else if (this.state.mode === "update") {
      const _content = this.getReadContent();
      if (_content) {
        _article = (
          <UpdateContent
            data={_content}
            onSubmit={function (_id, _title, _desc) {
              const _contents = Array.from(this.state.contents);
              for (let i = 0; i < _contents.length; i++) {
                if (_contents[i].id === _id) {
                  _contents[i] = { id: _id, title: _title, desc: _desc };
                  break;
                }
              }
              this.setState({
                contents: _contents,
                mode: "read",
              });
            }.bind(this)}
          ></UpdateContent>
        );
      }
    }
    return _article;
  }

  render() {
    console.log("App render");
    return (
      <Router>
        <div className="App">
          <Subject
            title={this.state.subject.title}
            sub={this.state.subject.sub}
            onChangePage={function () {
              this.setState({ mode: "welcome" });
            }.bind(this)}
          ></Subject>
          <TOC data={this.state.contents}></TOC>
          <Control
            onChangeMode={function (_mode) {
              if (_mode === "delete") {
                if (window.confirm("really?")) {
                  const _contents = Array.from(this.state.contents);
                  for (let i = 0; i < _contents.length; i++) {
                    if (_contents[i].id === this.state.selected_content_id) {
                      _contents.splice(i, 1);
                      break;
                    }
                  }
                  this.setState({
                    mode: "welcome",
                    contents: _contents,
                  });
                  alert("삭제됨");
                }
              } else {
                this.setState({
                  mode: _mode,
                });
              }
            }.bind(this)}
          ></Control>
          <Routes>
            <Route
              path="/:category/:file"
              element={<MarkdownViewerWrapper />}
            />{" "}
          </Routes>
          {this.getContent()}
        </div>
      </Router>
    );
  }
}

export default App;
