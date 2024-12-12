const http = require("http");
const fs = require("fs");
const url = require("url");
const qs = require("querystring");
const template = require("./lib/template.js");
const path = require("path");
const sanitizeHTML = require("sanitize-html");
const marked = require("marked");

const app = http.createServer(function (request, response) {
  const _url = request.url;
  const parsedUrl = url.parse(_url, true);
  const queryData = parsedUrl.query;
  const pathname = parsedUrl.pathname;
  const dir = queryData.dir || ""; // 디렉토리 선택
  let title = queryData.id;
  if (pathname === "/") {
    if (!queryData.dir) {
      // 루트 페이지: 디렉토리 목록 표시
      fs.readdir("./data", function (error, directories) {
        const title = "Welcome";
        const description = "학습할 주제를 선택하세요.";
        const list = template.list(
          directories.map((dir) => ({ name: dir, isDirectory: true })),
          ""
        );
        const html = template.HTML(
          title,
          list,
          `<h2>${title}</h2><p>${description}</p>`,
          ``
        );
        response.writeHead(200);
        response.end(html);
      });
    } else if (!queryData.id) {
      // 특정 디렉토리 내용 표시
      const dir = queryData.dir;
      fs.readdir(`./data/${dir}`, function (error, filelist) {
        const title = dir;
        const description = `${dir} 노트 목록`;
        const list = template.list(
          filelist.map((file) => ({ name: file, isDirectory: false })),
          dir
        );
        const html = template.HTML(
          title,
          list,
          `<h2>${title}</h2><p>${description}</p>`,
          `<a href="/create?dir=${dir}">Create</a>`
        );
        response.writeHead(200);
        response.end(html);
      });
    } else {
      // 특정 파일 내용 표시
      const filteredID = path.parse(queryData.id).base;
      const dir = queryData.dir;
      fs.readFile(`data/${dir}/${filteredID}`, "utf8", function (err, content) {
        if (err) {
          response.writeHead(404);
          response.end("File not found");
          return;
        }
        const sanitizedTitle = sanitizeHTML(queryData.id);
        const htmlContent = marked.parse(content); // 마크다운을 HTML로 변환
        const sanitizedDescription = sanitizeHTML(htmlContent);
        fs.readdir(`./data/${dir}`, function (error, filelist) {
          const list = template.list(
            filelist.map((file) => ({ name: file, isDirectory: false })),
            dir
          );
          const html = template.HTML(
            sanitizedTitle,
            list,
            `<h2>${sanitizedTitle}</h2>${sanitizedDescription}`, // 변환된 HTML 사용
            `<a href="/create?dir=${dir}">Create</a> 
           <a href="/update?id=${sanitizedTitle}&dir=${dir}">Update</a>
           <form action="/delete_process" method="post" onsubmit="return confirm('정말로 삭제합니까?');">
             <input type="hidden" name="id" value="${sanitizedTitle}">
             <input type="hidden" name="dir" value="${dir}">
             <input type="submit" value="delete">
           </form>`
          );
          response.writeHead(200);
          response.end(html);
        });
      });
    }
  } else if (pathname === "/create") {
    fs.readdir(`./data/${dir}`, function (err, filelist) {
      const title = "Create Note";
      const list = template.list(filelist.map((file) => `${dir}/${file}`));
      const html = template.HTML(
        title,
        list,
        `<form action="/create_process" method="post">
           <input type="hidden" name="dir" value="${dir}">
           <p><input type="text" name="title" placeholder="title" /></p>
           <p><textarea name="description" placeholder="description"></textarea></p>
           <p><input type="submit" /></p>
         </form>`,
        ``
      );
      response.writeHead(200);
      response.end(html);
    });
  } else if (pathname === "/create_process") {
    let body = "";
    request.on("data", function (data) {
      body += data;
    });
    request.on("end", function () {
      const post = qs.parse(body);
      const dir = post.dir;
      const title = post.title;
      const description = post.description;
      fs.writeFile(
        `data/${dir}/${title}.md`,
        description,
        "utf-8",
        function (err) {
          response.writeHead(302, {
            Location: `/?id=${encodeURIComponent(
              title
            )}.md&dir=${encodeURIComponent(dir)}`,
          });
          response.end();
        }
      );
    });
  } else if (pathname === "/update") {
    fs.readdir(`./data/${dir}`, function (err, filelist) {
      const fileteredID = path.parse(queryData.id).base;
      fs.readFile(
        `data/${dir}/${fileteredID}`,
        "utf-8",
        function (err, description) {
          const list = template.list(filelist.map((file) => `${dir}/${file}`));
          const html = template.HTML(
            queryData.id,
            list,
            `<form action="/update_process" method="post">
             <input type="hidden" name="id" value="${queryData.id}" />
             <input type="hidden" name="dir" value="${dir}" />
             <p><input type="text" name="title" value="${queryData.id.replace(
               ".md",
               ""
             )}" /></p>
             <p><textarea name="description">${description}</textarea></p>
             <p><input type="submit" /></p>
           </form>`,
            ``
          );
          response.writeHead(200);
          response.end(html);
        }
      );
    });
  } else if (pathname === "/update_process") {
    let body = "";
    request.on("data", function (data) {
      body += data;
    });
    request.on("end", function () {
      const post = qs.parse(body);
      const id = post.id;
      const title = post.title;
      const dir = post.dir;
      const description = post.description;
      fs.rename(
        `data/${dir}/${id}`,
        `data/${dir}/${title}.md`,
        function (error) {
          fs.writeFile(
            `data/${dir}/${title}.md`,
            description,
            "utf-8",
            function (err) {
              response.writeHead(302, {
                Location: `/?id=${encodeURIComponent(
                  title
                )}.md&dir=${encodeURIComponent(dir)}`,
              });
              response.end();
            }
          );
        }
      );
    });
  } else if (pathname === "/delete_process") {
    let body = "";
    request.on("data", function (data) {
      body += data;
    });
    request.on("end", function () {
      const post = qs.parse(body);
      const id = post.id;
      const dir = post.dir;
      const fileteredID = path.parse(id).base;
      fs.unlink(`data/${dir}/${fileteredID}`, function (error) {
        response.writeHead(302, {
          Location: `/?dir=${encodeURIComponent(dir)}`,
        });
        response.end();
      });
    });
  } else {
    response.writeHead(404);
    response.end("404 Not Found");
  }
});

app.listen(3000);
console.log("Server running at http://localhost:3000/");
