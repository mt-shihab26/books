package algos

import org.slf4j.LoggerFactory

object Calc {
    private val LOGGER = LoggerFactory.getLogger(Calc::class.java)
    @JvmStatic
    fun divide(x: Int, y: Int): Int {
        for (i in 1..1000) {
            LOGGER.info("dummy log")
        }
        return try {
            LOGGER.debug("Going to divide {} by {}", x, y)
            val result = x / y
            LOGGER.info("result is: {}", result)
            result
        } catch (e: Exception) {
            LOGGER.error("Error dividing {} by {} ", x, y, e)
            throw e
        }
    }
}