# java-web-programming

জাভা ওয়েব প্রোগ্রামিং (ANM Bazlur Rahman) Book's Code Collection

<!-- Sep 30, 2022 to Oct 9, 2022 -> total 10 days take, total page number is 344 -->

## Stuff Used

-   Servlet Container
    -   'Tomcat' as servlet container that handle req/res
-   Request Response:
    -   Handling request response with 'Servlet'
-   Templating:
    -   Writing template with 'jsp'
    -   Write JSP with 'jstl'
-   Automate Testing:
    -   Unit Testing with 'junit'
    -   Mocking with 'mockito'
-   Logging:
    -   Logging stuff with 'logback'
-   Data Validation
    -   Validating stuff with 'Jakarta Bean Validation'
-   Authentication
    -   Authenticate user with HTTP Session
-   Database
    -   Use 'MySQL' with JDBC
    -   As Connection Pool use 'HikariCP'
-   Dependency Injection
    -   Use 'Jboss weld servlet' for dependency injection
-   Transaction Management
-   Dependency Management and Build Tools
    -   'Gradle' as dependency management tools

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

## Chapter 03: Project Bootstrapping

-   We can divide card work in to three step:
    -   Show product in web page (Servlet Layer)
    -   Sorting the product (Service Layer)
    -   Read product from source (Repository Layer)
-   Data Transfer Object (DTO)
-   Standard Tag Library (JSTL)
-   Webjar: webjars.org
-   In logback, we will work with 3 class: Logger, Appender and Layout
-   Logging levels: TRACE < DEBUG < INFO < WARN < ERROR
-   Appender:
    -   ConsoleAppender
    -   FileAppender
    -   RollingFileAppender
    -   SMTPAppender
    -   DBAppender
-   Appender info: https://logback.qos.ch/manual/appenders.html
-   Making logs location
    ```shell
    cd /tmp
    mkdir logs
    chmod -R 755 logs
    touch application.log
    ```

## Chapter 04: Signup/Login

-   Signup step:
    -   Separate parameter from request
    -   Verify the given data
    -   Sort the username and password
-   The objects that are saved in the database are called domain
-   Jakarta Bean Validation library: https://beanvalidation.org
-   Jakarta Bean Validation annotation called constraint
-   SingleTon pattern in ValidationUtil class
-   HTTP Session
-   Custom Expression Language

## Chapter 05: Making Shopping Cart

-   Servlet Filter

## Chapter 06: Checkout and Order placing

-   JavaScript fetch api: https://javascript.info/fetch

## Chapter 07: Database & JDBC

-   MySQL Installation in Ubuntu
    -   `sudo apt update`
    -   `sudo apt install mysql-server`
    -   `sudo systemctl start mysql.service`
    -   `sudo mysql`
    -   `ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY '2611';`
-   Utility Commands
    -   `SHOW DATABASES;`
    -   `CREATE DATABASE eshoppers;`
    -   `USE eshoppers;`
-   Some GUI MySQL client
    -   MySQL Workbench
    -   TablePlus
    -   Sequel Pro
    -   DataGrip
-   Java Database Connectivity (JDBC)
-   Facade Pattern
-   JDBC created with Facade design pattern
-   Database URL in jdbc connection
    -   `jdbc:mysql:localhost:3306/`
    -   `jdbc:postgresql:localhost:5432/`
-   Data definition language (DDL): We define table schema with that
-   Data Manipulation language (DML): We do CRUD operation with that
-   Database Connection Pool
-   Delegator Design Pattern
-   Database Connection Pool Library
    -   Apache Commons DBCP
    -   HikariCP
    -   C3PO

## Chapter 08: JDBC Repository

-   One-to-many Relationship
-   Foreign Key
-   varargs array
-   sql join

## Chapter 09: Inversion of Control and Dependency Injection

-   dependant
-   dependency
-   class A -> class B : class A is dependent on class B, here class A is Dependant and class B is Dependency
-   There are two type of dependency
    -   Strongly coupled dependency
    -   Loosely coupled dependency
-   Inversion of control
-   Stop-the-World
-   Providing Dependency from outside of need class called dependency injection
-   Dependency injector also known as Container or Provider
-   Container give some service on runtime
-   Object life cycle management
-   Provide dependency
-   Tomcat is a servlet container. It gives servlet on runtime and manage it,
    That way Dependency injector in a container that gives dependency and mange it.
-   IoC Container: Giving responsibility of creating dependency object called IoC Container
-   Java Ecosystem has some IoC Container:
    -   Spring Framework Core
    -   JBoss Seam
    -   Google Guice
    -   Dagger
-   'CDI' is the standardized version of IoC Container that is standardized on 2009 at Java EE 6
-   Context and Dependency Injection (CDI)
-   The classes that CDI manage are called 'CDI Bean'
-   CDI Bean also called Managed Object
-   CDI is specification. It has more than one implementation:
    -   JBoss Weld (this book use)
    -   Apache OpenWebBeans
    -   CanDI

## Chapter 09: Transaction Management

-   Transaction Management
-   Request Scoped Bean: @RequestScoped -> The bean which life end with request
-   Session Scoped Bean: @SessionScoped -> The bean which life end with one user session
-   Application scoped Bean: @ApplicationScoped
-   Singleton Bean: @Singleton
-   @Dependent is default
-   We can use @RequestScoped Bean for transaction
-   Execute Around Pattern
-   In eshoppers-cdi-transaction product we have cdi container code and transaction code together.

## Exercise

-   এই অ্যাপ্লিকেশনে সাধারণ ইউজার হিসেবে লগইন করা গেলেও এডমিন ইউজার হিসেবে লগইন করার উপায় নেই। হিন্ট: ইউজার ক্লাসে একটি নতুন ফিল্ট তৈরি করুন। এর নাম দিন role এটি এনাম হতে পারে। সাধারণ ব্যবহারকারীদের জন্য এর ভ্যালু হতে পারে ROLE_USER । এডমিন ইউজারের জন্য এর ভ্যালু হতে পারে ROLE_ADMIN । লগইন করার পর AuthFilter এর doFilter() মেথডে কারেন্ট নিউজ অবজেক্ট থেকে রোল পরীক্ষা করে দেখতে পারি। এডমিন হলে তাকে এডমিন পেজে আর সাধারন ইউজার হলে তাকে হোমপেজে পাঠিয়ে দিতে পারি।
-   এই অ্যাপ্লিকেশনের হোমপেজে নানা রকম প্রোডাক্ট এর তথ্য থাকলেও এতে নতুন করে প্রোডাক্ট যুক্ত করার সহজ কোন উপায় নেই। একজন এডমিন ইউজার যাতে করে সহজে নতুন প্রোডাক্ট তৈরি করতে পারে সেরকম একটি পেজ তৈরি করুন। হিন্ট: এটি এমন ভাবে তৈরি করতে হবে, যাতে এডমিন ইউজার ছাড়া অন্য কেউ এই পেজে প্রবেশ করতে না পারে।
-   হোমপেজে প্রোডাক্ট সার্চ করার জন্য একটি সার্চ বার যুক্ত করুন
-   হোমপেজে একসাথে সবগুলো প্রোডাক্ট না দেখিয়ে Pagination যুক্ত করুন। হিন্ট: প্রতি পেজে 20 টি করে প্রডাক্ট দেখানো যেতে পারে। মাইএসকিউএল কুয়েরিতে limit কিওয়ার্ড ব্যবহার করা যেতে পারে।
-   অ্যাপ্লিকেশনে অর্ডার তৈরি করার আগে পেমেন্ট নেওয়ার পেজ যুক্ত করুন। পেমেন্ট দুই ভাবে নেওয়া যেতে পারে ক্যাশ অন ডেলিভারি কিংবা অনলাইন পেমেন্ট। যেমন: বিকাশ ইত্যাদি।
-   অর্ডার তৈরি হয়ে গেলে অর্ডারের বিবরণটি ইউজারকে ইমেইলে জানিয়ে দিন। হিন্ট: জাভা অ্যাপ্লিকেশন থেকে ইমেইল করার জন্য Java Mail নামের একটি এপিআই রয়েছে

## Appendix

-   https://mvnrepository.com/
-   Apache Commons Lang
-   Java Archive (.jar)
-   Dependency Management and Build Tool for Java: Ant, Maven, Gradle
-   We use gradle here
-   Gradle commands
    -   `gradle -v`
    -   `gradle init`
    -   `gradle build` or `./gradlew build`
    -   `gradle tasks`
    -   `gradle clean` for cleaning build directory
    -   `gradle test`
    -   `gradle build -x test` for building project without test
    -   `gradle dependencies`
    -   ``
-   Gralde Repositores
    -   mavenCentral()
    -   google()
    -   jcenter()
-   Getting To Know Your IDE: https://youtube.com/playlist?list=PLPZy-hmwOdEXdOtXdFzyx_XCnrF_oD2Ft
