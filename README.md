# java-web-programming

জাভা ওয়েব প্রোগ্রামিং (ANM Bazlur Rahman) Book's Code Collection

## Stuff

- Tomcat
- Servlet
- Templating:
  -  Writing template with 'jsp'
  -  Write JSP with 'jstl'
- Testing:
  -  Unit Testing with 'junit'
  -  Mocking with 'mockito'
- Logging:
  -  Logging stuff with 'logback'

## Links

-   https://github.com/MasterDevSkills/java-web-programming-book

## Chapter 01: Web and Web Application

-   সংক্ষেপে ওয়েব হলো, পৃথিবীর বিভিন্ন অংশে ছড়িয়ে ছিটিয়ে থাকা অসংখ্য কম্পিউটারের ওয়েব সার্ভারে সংরক্ষিত ডকুমেন্টের সংগ্রহ যাদের নির্দিষ্ট ঠিকানা রয়েছে
-   ওয়েব সার্ভার ও ওয়েব ক্লায়েন্ট। সার্ভার এর সঙ্গে যোগাযোগ করে আমরা যে ডকুমেন্ট পড়তে চাই সেই ডকুমেন্টই ক্লায়েন্টের মেশিন বিশেষ অ্যাপ্লিকেশন (ওয়েব ব্রাউজার) প্রদর্শন করে
-   HTTP Request format has three section: Start line, Headers and Body. Start Line has three section: Method URL, HTTP Version and Headers is key-value pair data.
-   HTTP Response format has three section as well: Start Line, Header and Body. In Start Line we have two sections: HTTP Version and HTTP Response Code. Header is also key-value pair data. Body is the actual content, normally it is text data, but it can be binary data.
-   URI and URL. URL has four section: Protocol, Hostname, Port and Path.
-   TCP/IP model has 4 layer: Application Layer, Transport Layer, Internet Layer and Link Layer.
-   Application Layer communicate with Transport Layer with defied port. Like 80 in HTTP Protocol. HTTP is Application Layer Protocol.
-   We commonly used http methods: GET, POST, PUT, DELETE
-   HTTP Status Code:
    -   Informational Responses (1xx)
    -   Successful Responses(2xx):
        -   200 Ok: If every this ok
        -   201 Created: If any resource created
        -   202 Accepted: If server accept the request not giving response now.
        -   204 No Content: If body has no content
    -   Redirects(3xx):
        -   301 Move Permanently
        -   302 Found
    -   Client Errors (4xx):
        -   400 Bad Request
        -   401 Unauthorized
        -   403 Forbidden: If not receiving the request
        -   404 Not Found
        -   405 Method not Allowed
    -   Server Errors (5xx):
        -   500 Internal Server Error
        -   501 Not Implemented: If request is beyond the server limit.
        -   502 Bad Gateway: If server and proxy server has problem.
        -   503 Service Unavailable: If service is temporarily unavailable.
        -   504 Gateway Timeout: If server taking too much time to giving response
-   We have some web server to server pages:
    -   Apache HTTP Server
    -   Internet Information Services(IIS)
    -   NGINX
    -   Apache Tomcat
    -   Jetty

## Chapter 02: Servlet and Tomcat

-   সার্ভলেট হলো একটি জাভা অবজেক্ট যা এইচটিটিপি রিকোয়েস্ট বুঝতে পারে এবং সে অনুযায়ী রেসপন্স প্রদান করে।
-   এই জাভা সার্ভলেট অবজেক্টটি হোস্ট করার জন্য একটি সার্ভলেট কন্টেইনার প্রয়োজন হয়। জাভা সার্ভলেট হোস্ট করার জন্য একাধিক সার্ভলেট কন্টেইনার রয়েছে তবে Apache Tomcat অন্যতম
-   https://adoptopenjdk.net for openjdk download
-   Installing Tomcat
    -   `sudo mv ~/Downloads/apache-tomcat-9.0.67.tar.gz /usr/local`
    -   `cd /usr/local`
    -   `sudo tar -xvf apache-tomcat-9.0.67.tar.gz`
    -   `sudo mv apache-tomcat-9.0.67 tomcat-9`
    -   `sudo chown -R shihab4t tomcat-9`
    -   `sudo chmod +x tomcat-9/bin/*.sh`
    -   `cd /usr/local/tomcat-9/bin`
    -   `./catalina.sh start` server is started in 8080 port
-   https://github.com/MasterDevSkills/shopping-cart-starter
-   Running app In Tomcat ->
    -   `mv shopping-cart-starter-1.0-SNAPSHOT.war cart.war`
    -   `cp cart.war /usr/local/tomcat-9/webapps`
    -   `cd /usr/local/tomcat-9/bin`
    -   `./catalina.sh start`
-   Checking is tomcat running:
    -   `ps -ef | grep tomcat`
    -   `ps -ef | grep tomcat | awk '{print $2}' | xargs kill -9`
-   Gradle commands:
    -   `gradle build`
    -   `gradle clean`
    -   `gradle clean build`
-   Creating tomcat manager account
    -   `vi /usr/local/tomcat-9/conf/tomcat-users.xml`
    -   add this two line
        ```
        <role rolename="manager-gui" />
        <user username="admin" password="shihab" roles="manager-gui"
        ```
-   Servlet life cycle
    -   servlet load
    -   creating servlet instance
    -   invoking servlet init() method
    -   invoking servlet service() method
    -   invoking servlet destroy() method
-   Servlet lifer cycle controlled by servlet container, we as programmer put our code in this method
-   JavaServer Pages (jsp)

## Chapter 03

-   Data Transfer Object (DTO)
-   Standard Tag Library (JSTL)
-   Webjar: webjars.org
-   In logback, we will work with 3 class: Logger, Appender and Layout
-   Logging levels: TRACE < DEBUG < INFO < WARN < ERROR
