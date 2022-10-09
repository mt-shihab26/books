<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<jsp:include page="includes/header.jsp" />
<jsp:include page="includes/navigation.jsp" />

<div class="container">
    <br/>
    <div>
        <form
            method="post"
            role="form"
            class="form-horizontal"
            action="<c:url value="/order" />"
        >
            <div class="row">
                <div class="col-md-4 order-md-2 mb-4">
                    <h4 class="d-flex justify-content-between align-items-center mb-3">
                        <span class="text-muted">
                            Your cart
                        </span>
                        <span class="badge badge-secondary badge-pill">
                            <c:out value="${cart.totalItem}" />
                        </span>
                    </h4>
                    <ul class="list-group mb-3">
                        <c:forEach var="cartItem" items="${cart.cartItems}">
                            <li class="list-group-item d-flex justify-content-between lh-condensed">
                                <div>
                                    <h6 class="my-0">
                                        <c:out value="${cartItem.product.name}"/>
                                        <small class="badge badge-info">
                                            <c:out value="${cartItem.quantity}" />
                                        </small>
                                    </h6>
                                    <small class="text-muted">
                                        <c:out value="${cartItem.product.description}" />
                                    </small>
                                </div>
                                <span class="text-muted">
                                    $<c:out value="${cartItem.price}" />
                                </span>
                            </li>
                        </c:forEach>
                        <li class="list-group-item d-flex justify-content-between">
                            <span>Total (USD)</span>
                            <strong>
                                $<c:out value="${cart.totalPrice}"/>
                            </strong>
                        </li>
                    </ul>
                </div>
                <div class="col-md-8 order-md-1">
                    <h4 class="mb-3">
                        Shipping address
                    </h4>
                    <div class="mb-3">
                        <label for="address">Address</label>
                        <input
                            type="text"
                            name="address"
                            id="address"
                            class="form-control"
                            placeholder="1234 Main ST"
                            value="${shippingAddress.address}"
                            required
                        />
                        <c:if test="${errors.address != null}">
                            <small class="text-danger">
                                ${errors.address}
                            </small>
                        </c:if>
                    </div>
                    <div class="mb-3">
                        <label for="address2">
                            Address 2
                            <span class="text-muted">
                                (Optional)
                            </span>
                        </label>
                        <input
                            type="text"
                            name="address2"
                            id="address2"
                            class="form-control"
                            placeholder="Apartment or suite"
                            value="${shippingAddress.address2}"
                        />
                        <c:if test="${errors.address2 != null}">
                            <small class="text-danger">
                                ${errors.address}
                            </small>
                        </c:if>
                    </div>
                </div>
                <div class="row">
                    <div class="col-md-5 mb-3">
                        <label for="country">Country</label>
                        <select name="country" id="country" class="custom-select d-block w-100" required>
                            <option value="">Choose...</option>
                            <c:forEach var="country" items="${countries}">
                                <option
                                    value="${country}"
                                    ${country == shippingAddress.country ? 'selected="selected"' : ''}
                                >
                                    ${country}
                                </option>
                            </c:forEach>
                        </select>
                        <c:if test="${errors.country != null}">
                            <small class="text-danger">
                                ${errors.country}
                            </small>
                        </c:if>
                    </div>
                    <div class="col-md-4 mb-3">
                        <label for="state">State</label>
                        <input
                            type="text"
                            name="state"
                            id="state"
                            class="form-control"
                            value="${shippingAddress.state}"
                            placeholder="State"
                        >
                        <c:if test="${errors.state != null}">
                            <small class="text-danger">
                                ${errors.state}
                            </small>
                        </c:if>
                    </div>
                    <div class="col-md-3 mb-3">
                        <label for="" class="zip">Zip</label>
                        <input
                            type="text"
                            class="form-control"
                            id="zip"
                            name="zip"
                            placeholder=""
                            value="${shippingAddress.zip}"
                            required
                        />
                        <c:if test="${errors.zip != null}">
                            <small class="text-danger">
                                ${errors.zip}
                            </small>
                        </c:if>
                    </div>
                    <div class="col-md-3 mb-3">
                        <label for="mobileNumber">
                            Phone Number
                            <span class="text-muted">
                                (Optional)
                            </span>
                        </label>
                        <input
                            type="text"
                            class="form-control"
                            id="mobileNumber"
                            name="mobileNumber"
                            placeholder="+8801xxxxxxxxx"
                            value="${shippingAddress.mobileNumber}"
                            required
                        />
                        <c:if test="${errors.mobileNumber != null}">
                            <small class="text-danger">
                                ${errors.mobileNumber}
                            </small>
                        </c:if>
                    </div>

                    <hr class="mb-4">
                    <hr class="mb-4">

                    <button type="submit" class="btn btn-primary-btn-lg btn-block">
                        Continue to checkout
                    </button>
                </div>
            </div>
        </form>
    </div>
</div>

<jsp:include page="includes/footer.jsp" />
