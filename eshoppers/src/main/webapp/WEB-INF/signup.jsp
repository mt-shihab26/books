<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<jsp:include page="includes/header.jsp" />
<jsp:include page="includes/navigation.jsp" />

<div class="container">
    <br />

    <h2 class="h2">Sign Up</h2>
    <hr class="mb-4" />

    <form 
        role="form"
        class="form-horizontal"
        method="post"
        action="<c:url value="/signup" />" 
    >
        <div class="form-group">
            <label for="username">Username</label>
            <input 
                type="text"
                name="username"
                id="username"
                class="form-control"
                placeholder=""
            />
        </div>

        <div class="form-group">
            <label for="email">Email</label>
            <input 
                type="text"
                name="email"
                id="email"
                class="form-control"
                placeholder="you@example.com"
            />
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
        </div>

        <div class="form-group">
            <label for="passwordConfirmed">Password Confirmed</label>
            <input 
                type="password"
                name="passwordConfirmed"
                id="passwordConfirmed"
                class="form-control"
                placeholder=""
            />
        </div>

        <div class="form-group">
            <label for="firstname">First Name</label>
            <input 
                type="text"
                name="firstname"
                id="firstname"
                class="form-control"
                placeholder=""
            />
        </div>

        <div class="form-group">
            <label for="lastname">Last Name</label>
            <input 
                type="text"
                name="lastname"
                id="lastname"
                class="form-control"
                placeholder=""
            />
        </div>

        <hr class="mb-4" />
        <div class="form-group">
            <button type="submit" class="btn btn-primary btn-lg">
                Signup
            </button>
        </div>

    </form>
</div>

<jsp:include page="includes/footer.jsp" />
