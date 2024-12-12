// lib/template.js
const template = {
  HTML: function (title, list, body, control) {
    return `
          <!doctype html>
          <html>
          <head>
            <title>WEB1 - ${title}</title>
            <meta charset="utf-8">
            <style>
              body { font-family: Arial, sans-serif; line-height: 1.6; padding: 20px; }
              h1, h2, h3, h4, h5, h6 { margin-top: 24px; margin-bottom: 16px; }
              p { margin-bottom: 16px; }
              code { background: #f4f4f4; padding: 2px 5px; border-radius: 3px; }
              pre { background: #f4f4f4; padding: 16px; overflow-x: auto; }
            </style>
          </head>
          <body>
            <h1><a href="/">WEB</a></h1>
            ${list}
            ${control}
            ${body}
          </body>
          </html>
        `;
  },
  list: function (items, currentDir) {
    let list = "<ul>";
    items.forEach((item) => {
      if (item.isDirectory) {
        list += `<li><a href="/?dir=${item.name}">${item.name}/</a></li>`;
      } else {
        list += `<li><a href="/?id=${item.name}&dir=${currentDir}">${item.name}</a></li>`;
      }
    });
    list += "</ul>";
    return list;
  },
};

module.exports = template;
