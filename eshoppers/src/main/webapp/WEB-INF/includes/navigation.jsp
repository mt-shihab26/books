<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
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
        <li class="nav-item"><a href="<c:url value="/signup" />" class="nav-link">Signup</a></li>
    </ul>
    </div>
</div>
</nav>