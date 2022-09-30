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
<body style="padding-top: 70px">
    <nav class="navbar navbar-expand-lg navbar-dark bg-dark fixed-top">
    <div class="container">
        <a class="navbar-brand" href="<c:url value="/"/>">e-Shoppers</a>
        <button 
            class="navbar-toggler"
            type="button"
            data-toggle="collapse"
            data-target="#navbarResponsive"
            aria-controls="navbarResponsive"
            aria-expanded="false"
            aria-label="Toggle navigation"
        >
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navberResponsive">
        <ul class="navbar-nav ml-auto">
            <li class="nav-item active"><a href="<c:url value="/"/>" class="nav-link">Home</a></li>
            <li class="nav-item"><a href="#" class="nav-link">About</a></li>
        </ul>
        </div>
    </div>
    </nav>
    <div class="container">
        <div class="jumbotron">
            <h1>Welcome to e-shoppers!</h1>
            <img 
                src="<c:url value="/img/cart.jpg"/>"
                style="height: 200px"
                alt=""
            />
        </div>

        <div class="row">
            <c:forEach var="product" items="${products}">
                <div class="col-sm-4">
                <div class="card h-100 mb-4">
                <div class="card-body">
                    <h5 class="card-title"><c:out value="${product.name}"/></h5>
                    <p class="card-text"><c:out value="${product.description}"/></p>
                    <p class="card-text">Price: $<c:out value="${product.price}"/></p>
                    <a href="#" class="card-link btn btn-outline-info">Add toCart</a>
                </div>
                </div>
                </div>
            </c:forEach>
        </div>

        <!-- <table class="table">
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
        </table> -->
    </div>

    <footer class="footer mt-auto py-3 fixed-botton">
        <div class="container">
            <span class="text-muted">Copyright &copy; eShoppers</span>
        </div>
    </footer>


    <!-- <%--

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
     --%> -->
</body>
</html>