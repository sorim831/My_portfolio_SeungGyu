const jwt = require("jsonwebtoken");
exports.verifyToken = (req, res, next) => {
  const token = req.headers.authorization.split(" ")[1];

  // 인증 완료
  try {
    req.decoded = jwt.verify(token, process.env.JWT_SECRET);
    return next();
  } catch (error) {
    // 인증 실패
    if (error.name === "TokenExpireError") {
      return res.status(419).json({
        code: 419,
        message: "토큰이 만료되었습니다.",
      });
    }
    return res.status(401).json({
      code: 401,
      message: "유효하지 않은 토큰입니다.",
    });
  }
};
