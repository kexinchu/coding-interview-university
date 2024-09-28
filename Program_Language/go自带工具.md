### go 工具

#### 概述
```
[work@computer output]$ go
Go is a tool for managing Go source code.

Usage:

        go <command> [arguments]

The commands are:

        bug         start a bug report
        build       compile packages and dependencies
        clean       remove object files and cached files
        doc         show documentation for package or symbol
        env         print Go environment information
        fix         update packages to use new APIs
        fmt         gofmt (reformat) package sources
        generate    generate Go files by processing source
        get         add dependencies to current module and install them
        install     compile and install packages and dependencies
        list        list packages or modules
        mod         module maintenance
        run         compile and run Go program
        test        test packages
        tool        run specified go tool
        version     print Go version
        vet         report likely mistakes in packages

Use "go help <command>" for more information about a command.

Additional help topics:

        buildconstraint build constraints
        buildmode       build modes
        c               calling between Go and C
        cache           build and test caching
        environment     environment variables
        filetype        file types
        go.mod          the go.mod file
        gopath          GOPATH environment variable
        gopath-get      legacy GOPATH go get
        goproxy         module proxy protocol
        importpath      import path syntax
        modules         modules, module versions, and more
        module-get      module-aware go get
        module-auth     module authentication using go.sum
        packages        package lists and patterns
        private         configuration for downloading non-public code
        testflag        testing flags
        testfunc        testing functions
        vcs             controlling version control with GOVCS

Use "go help <topic>" for more information about that topic.
```

#### go vet 检测代码的常见错误
- Printf类函数调用时，类型匹配错误的参数
- 定义常用方法时，方法签名的错误
- 错误的结构标签
- 没有指定字段名的结构字面量


#### go fmt 代码格式化


#### go doc 查看go语言文档
- 本机获取文档
```
go doc tar
```
- 网页浏览文档
```
godoc -http=:6060
```
- 添加自己的代码文档
按照如下规则注释代码文件即可
    - 在标识符之前，将自己想要的文档作为注释加入代码中
    - 这个规则对包，函数，类型，全局变量均可用
    ```
    // Retrieve 连接到配置库，收集各种链接配置、用户名、密码，这个函数成功时
    // 返回config结构，否则返回一个错误
    func Retrieve() (config, err) {
        // ... ... 
    }

    // 或者 多行的注释可以用下面的样式

    /*
        示例行1
        示例行2
    */
    ```