<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title> All Products </title>
    <link
        rel="stylesheet"
        type="text/css"
        href="${pageContext.request.contextPath}/webjars/bootstrap/4.6.2/css/bootstrap.min.css"
    />
</head>
<body>
    <div class="container">
        <table class="table">
            <thead>
            <tr>
                <th>Name</th>
                <th>Description</th>
                <th>Price</th>
            </tr>
            <thead>
            <tbody>
            <c:forEach var="product" items="${products}">
                <tr>
                    <td><c:out value="${product.name}"/></td>
                    <td><c:out value="${product.description}"/></td>
                    <td><c:out value="${product.price}"/></td>
                </tr>
            </c:forEach>
            </tbody>
        </table>
    </div>


    <%--

    <h3> Tag Library </h3>
    <c:if test="${age < 18}">
        <c:out value="You are not eligible for voting!"/>
    </c:if>

    <c:choose>
        <c:when test="${condition1}">
            // do something if condition1 is true
        </c:when>
        <c:when test="${condition2}">
            // do something if condition2 is true
        </c:when>
        <c:otherwise>
            // do something if all condition is false
        </c:when>
    </c:choose>

    <c:url value="/anotherUrl" />
     --%>
</body>
</html>