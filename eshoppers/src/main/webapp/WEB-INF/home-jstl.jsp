<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<jsp:include page="includes/header.jsp" />
<jsp:include page="includes/navigation.jsp" />

<div class="container">
    <div class="jumbotron">
        <c:if test="${sessionScope.user != null}">
        <h1>Hello <c:out value="${sessionScope.user.firstname}"/></h1>
        </c:if>
        <h1>Welcome to e-shoppers!</h1>

        <img
            src="<c:url value="/img/cart.jpg"/>"
            style="height: 200px"
            alt="Cart Image"
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
                <p class="card-text">Rating: <c:out value="${product.rating}"/></p>
                <a href="#" class="card-link btn btn-outline-info">Add toCart</a>
            </div>
            </div>
            </div>
        </c:forEach>
    </div>
</div>

<jsp:include page="includes/footer.jsp" />
