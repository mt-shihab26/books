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
                required
                minlength="4"
                maxlength="32"
                value="${userDto.username}"
            />
            <c:if test="${errors.username != null}">
                <small class="text-danger">${errors.username}</small>
            </c:if>
        </div>

        <div class="form-group">
            <label for="email">Email</label>
            <input 
                type="text"
                name="email"
                id="email"
                class="form-control"
                placeholder="you@example.com"
                value="${userDto.email}"
            />
            <c:if test="${errors.email != null}">
                <small class="text-danger">${errors.email}</small>
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
                required
                minlength="6"
                maxlength="24"
            />
            <c:if test="${errors.password != null}">
                <small class="text-danger">${errors.password}</small>
            </c:if>
        </div>

        <div class="form-group">
            <label for="passwordConfirmed">Password Confirmed</label>
            <input 
                type="password"
                name="passwordConfirmed"
                id="passwordConfirmed"
                class="form-control"
                placeholder=""
                required
                minlength="6"
                maxlength="24"
            />
            <c:if test="${errors.passwordConfirmed != null}">
                <small class="text-danger">${errors.passwordConfirmed}</small>
            </c:if>
        </div>

        <div class="form-group">
            <label for="firstname">First Name</label>
            <input 
                type="text"
                name="firstname"
                id="firstname"
                class="form-control"
                placeholder=""
                required
                minlength="1"
                maxlength="32"
                value="${userDto.firstname}"
            />
            <c:if test="${errors.firstname != null}">
                <small class="text-danger">${errors.firstname}</small>
            </c:if>
        </div>

        <div class="form-group">
            <label for="lastname">Last Name</label>
            <input 
                type="text"
                name="lastname"
                id="lastname"
                class="form-control"
                placeholder=""
                required
                minlength="1"
                maxlength="32"
                value="${userDto.lastname}"
            />
            <c:if test="${errors.lastname != null}">
                <small class="text-danger">${errors.lastname}</small>
            </c:if>
        </div>

        <hr class="mb-4" />
        <div class="form-group">
            <button 
                type="submit"
                class="btn btn-primary btn-lg"
                onclick="validatePassword"
            >
                Signup
            </button>
        </div>

    </form>
</div>

<script type="text/javascript">
    const validatePassword = () => {
        const password = document.getElementsByName("password").value;
        const passwordConfirmed = document.getElementsByName("passwordConfirmed").value;

        if (password != passwordConfirmed) {
            alert("Passwords do not match.");
            return false;
        }
        return true;
    }
</script>

<jsp:include page="includes/footer.jsp" />
