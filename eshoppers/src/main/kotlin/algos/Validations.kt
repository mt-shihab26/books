package algos

import java.util.regex.Pattern

object Validations {
    fun email(email: String?): Boolean {
        if (email == null) return false
        val emailRegex = "^[a-zA-Z0-9_+&*-]+(?:\\." +
                "[a-zA-Z0-9_+&*-]+)*@" +
                "(?:[a-zA-Z0-9-]+\\.)+[a-z" +
                "A-Z]{2,7}$"
        val pat = Pattern.compile(emailRegex)
        return pat.matcher(email).matches()
    }

    fun strLen(str: String, min: Int, max: Int): Boolean {
        if (str.length < min) return false
        return str.length <= max
    }
}