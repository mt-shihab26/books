<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>

<head>
    <title>Meter Converter</title>
</head>

<body>
    <a href="/"><h1>Converter</h2></a>
        <a href="/convert">
        <h2>Celsius to Fahrenheit Converter</h2>
    </a>
    <a href="/meter-to-kilometer">
        <h2>Meter to Kilometer Converter</h2>
    </a>
    <form action="/meter-to-kilometer" method="post">
        <input type="number" name="meter" />
        <input type="submit" value="Submit" />
    </form>
</body>

</html>