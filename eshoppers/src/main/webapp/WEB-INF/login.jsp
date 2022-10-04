<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<jsp:include page="includes/header.jsp" />
<jsp:include page="includes/navigation.jsp" />

<div class="container">
    <br />

    <h2 class="h2">Login</h2>
    <hr class="mb-4" />

    <form
        role="form"
        class="form-horizontal"
        method="post"
        action="<c:url value="/login" />"
    >
        <div class="form-group">
            <label
                for="username"
            >
                Username
            </label>
            <input
                type="text"
                name="username"
                id="username"
                class="form-control"
                placeholder=""
            />
            <c:if test="${errors.username != null}">
                <small class="text-danger">${errors.username}</small>
            </c:if>
        </div>

        <div class="form-group">
            <label for="password">Password</label>
            <input
                type="password"
                name="password"
                id="password"
                class="form-control"
                placeholder=""
            />
            <c:if test="${errors.password != null}">
                <small class="text-danger">${errors.password}</small>
            </c:if>
        </div>

        <hr class="mb-4" />
        <div class="form-group">
            <button
                type="submit"
                class="btn btn-primary btn-lg"
            >
                Login
            </button>
        </div>

    </form>
</div>


<jsp:include page="includes/footer.jsp" />
