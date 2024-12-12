import React, { Component } from "react";
import { useParams } from "react-router-dom";
import Markdown from "react-markdown";

// Hook을 사용하여 라우팅 처리
function MarkdownViewerWrapper() {
  const { category, file } = useParams();
  return <MarkdownViewer category={category} file={file} />;
}

class MarkdownViewer extends Component {
  constructor(props) {
    super(props);
    this.state = {
      markdown: "",
    };
  }

  componentDidMount() {
    this.fetchMarkdownFile();
  }

  componentDidUpdate(prevProps) {
    if (
      prevProps.category !== this.props.category ||
      prevProps.file !== this.props.file
    ) {
      this.fetchMarkdownFile();
    }
  }

  fetchMarkdownFile() {
    const { category, file } = this.props;
    fetch(`${process.env.PUBLIC_URL}/data/${category}/${file}.md`)
      .then((response) => response.text())
      .then((data) => this.setState({ markdown: data }));
  }

  render() {
    return (
      <div>
        <h2>
          {this.props.category} - {this.props.file} 내용이 나와야지
        </h2>
        <Markdown>{this.state.markdown}</Markdown>
      </div>
    );
  }
}

export default MarkdownViewerWrapper;
