<%@ page import="com.shihabmahamud.eshoppers.dto.ProductDTO" %>
<%@ page import="java.util.List" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title> All Products </title>
</head>
<body>
    <% List<ProductDTO> products = (List<ProductDTO>) request.getAttribute("products"); %>
    <table>
        <thead>
        <tr>
            <th>Name</th>
            <th>Description</th>
            <th>Price</th>
        </tr>
        <thead>
        <tbody>
        <% for (ProductDTO product : products) {%>
        <tr>
            <td><%= product.getName()%></td>
            <td><%= product.getDescription()%></td>
            <td><%= product.getPrice()%></td>
        </tr>
        <%}%>
        </tbody>
    </table>
</body>
</html>

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
     --%>

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
        -->