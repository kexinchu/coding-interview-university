### 容器化环境的特点
- 通过Docker，百度的Matrix等容器技术，能提升RD对资源的利用率，更方便的管理资源。
- 容器和虚拟机类似，多个容器会共享同一台物理机上的资源。使一台物理机同时部署多个不同业务的APP。


补充：Matrix 是比虚拟机更轻量的容器技术，没有虚拟出 CPU 资源，而是直接使用宿主机的 CPU 资源，通过cgroup等技术来对cpu等资源进行分配和管理。但是，我们在Matrix容器里看到 cpu 的总核数 和直接在宿主机上看到的是一样的。


- 历史问题：http://wenda.baidu.com/ask/exp/76680?refer=infoflow-pc&logId=lcc6p3tin03p425a3iatg&groupIds=8&reportLog=true
- 说明： https://ku.baidu-int.com/knowledge/HFVrC7hq1Q/pKzJfZczuc/23UTe4mWYv/7iRR_OrD9ipMhX?source=102
- https://zhuanlan.zhihu.com/p/100165648


实际情况下：
配额这个 必须要设置在固定的核心上 再设置MAXPROCS 才有意义
必须是容器设置占用了固定的cpu核心。才能生效
否则，底层容器中的machine还是在被CPU竞争(物理核心8核；容器设置占用2核)