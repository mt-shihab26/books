<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>Temperature Converter</title>
    </head>
    <body>
        <h1>Celsius to Fahrenheit conversion</h1>
        <form action="/convert" method="post">
            <input type="number" name="temperature" />
            <input type="submit" value="Submit" />
        </form>
    </body>
</html>
