## GO

- go_path下的tour   websocket
- 工具： https://go.dev/play/    http   sleep是通过前端实现的

- int, int64, uint64 和 string 的互换
```
string转成int：
int, err := strconv.Atoi(string)
string转成int64：
int64, err := strconv.ParseInt(string, 10, 64)
string转成uint64：
int64, err := strconv.ParseUint(string, 10, 64)
int转成string：
string := strconv.Itoa(int)
int64转成string：
string := strconv.FormatInt(int64, 10)
uint64转成string：
string := strconv.FormatUint(uint64, 10)
```

#### strings 包
- strings.Split()
```
slice := strings.Split(strDemo, "&")
```

### GDP
- vsgo-app-topone
    - 入口： main.go -> bootstrap
    - router中指定了路由 /topone/api/vsdf



### gRPC