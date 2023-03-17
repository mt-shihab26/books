<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>

<head>
    <title>Temperature Converter</title>
</head>

<body>
    <a href="/"><h1>Converter</h2></a>
        <a href="/convert">
        <h2>Celsius to Fahrenheit Converter</h2>
    </a>

    <form action="/convert" method="post">
        <input type="number" name="temperature" />
        <input type="submit" value="Submit" />
    </form>

    <a href="/meter-to-kilometer">
        <h2>Meter to Kilometer Converter</h2>
    </a>
</body>

</html>