<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="sec" uri="http://bazlur.com/functions" %>
<jsp:include page="includes/header.jsp" />
<jsp:include page="includes/navigation.jsp" />

<div class="container">
    <div class="jumbotron">
        <c:if test="${sec:isAuthenticated(pageContext.request)}">
            <h1> Hello <c:out value="${sec:getCurrentUser(pageContext.request).firstname}"/>,
                Welcome to e-shoppers!
            </h1>
        </c:if>

        <img src="<c:url value="/img/cart.jpg"/>" style="height: 200px"
             alt=""/>
    </div>

    <div class="row">
        <c:forEach var="product" items="${products}">
            <div class="col-sm-4">
                <div class="card h-100 mb-4">
                    <div class="card-body">
                        <h5 class="card-title">
                            <c:out value="${product.name}"/>
                        </h5>
                        <p class="card-text">
                            <c:out value="${product.description}"/>
                        </p>
                        <p class="card-text">
                            Price: $ <c:out value="${product.price}"/>
                        </p>

                        <p onclick="addToCart(${product.id})" class="card-link btn btn-outline-info">
                            Add toCart
                        </p>
                        
                        <form 
                            style="visibility: hidden;" 
                            id="addToCart_${product.id}" 
                            method="post"
                            action="<c:url value="/add-to-cart?productId=${product.id}"/>"
                        >
                        </form>

                    </div>
                </div>
            </div>
        </c:forEach>
    </div>
</div>

<script>
    function addToCart(productId) {
        const form = document.getElementById("addToCart_" + productId);
        form.submit();
    }
</script>

<jsp:include page="includes/footer.jsp" />
