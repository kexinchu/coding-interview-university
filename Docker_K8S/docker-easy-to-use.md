## 安装 Docker


## 加载image + 新建container

- pull image
```shell
docker pull ubuntu:24.04
```

- 查看image
```shell
docker images
```

- create container
```shell
docker run -itd --name ubuntu-kexin ubuntu:24.04
```


## 查看 和 删除container

- 查看
```shell
docker ps
```

- 杀死进程
```shell
docker kill ${CONTAINER ID}
```

- 删除container
```shell
docker rm ${container}
```
