import React, { Component } from "react";
import { Link } from "react-router-dom";

class TOC extends Component {
  render() {
    const { data } = this.props;

    return (
      <nav>
        {data.map((content) => (
          <div key={content.id}>
            <h2>{content.title}</h2>
            <ul>
              {content.files.map((file, index) => (
                <li key={index}>
                  <Link to={`/${content.category}/${file.replace(".md", "")}`}>
                    {file}
                  </Link>
                </li>
              ))}
            </ul>
          </div>
        ))}
      </nav>
    );
  }
}

export default TOC;
