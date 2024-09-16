# Optimization

### Definition
- Optimization problems
    - determine value of optimization variable within feasible region/set to optimize optimization objective
    $$
    \min f(x) \quad \text{s.t.} \quad x \in F
    $$

    - Optimization variable  $ x \in \mathbb{R}^{n} $
    - Feasible region/set  $ \mathcal{F} \subset \mathbb{R}^{n} $
    - Optimization objective  $ f: \mathcal{F} \rightarrow \mathbb{R} $

- Optimal solution:  

$$  
x^{*} = \underset{x \in \mathcal{F}}{\operatorname{argmin}} f(x)

x \in \mathcal{F}
$$ 
- Optimal objective value  

$$ 
f^{*} = \min_{x \in \mathcal{F}} f(x) = f(x^{*}) 


x \in \mathcal{F}
$$

- Optimization Objective （优化目标）: $ f: \mathcal{F} \rightarrow \mathbb{R} $
    - $f(x) = 1$: Feasiblity problem 可能性问题
    - Simple functions
        - Convex function: 凸函数
        - Linear funtion： $f(x) = a^{T}x$
    - Complicated functions
        - Even can be implicitly represented throuogh an algorithm which takes $x \in \mathcal{F}$ as input, and outputs a value

##### Optimization is at the heart of many machine learning algorithms
- MLE: maximum likelihood estimation 最大似然估计
    $$
    \underset{\theta}{\text{maximize}}\ \mathcal{L}(\theta|X) = \log L(\theta|X) = \sum_{i}\log p(x_{i}|\theta)
    $$
- Linear regression
- Classification (logical regression or SVM)
- K-means clustering
    $$
    \underset{\mu_{1},\ldots,\mu_{k}}{\operatorname{minimize}}\ J(\mu) = \sum_{j=1}^{k}\sum_{i\in C_{j}}\left\|x_{i}-\mu_{j}\right\|^{2}
    $$

##### Many algorithms developed for special classes of optimization problems
- i.e. when $f(x)$ and $\mathcal{F}$ satisfy certain constraints.
- Linear programming(LP)
- Quadratic programming(QP)
- Convex optimization problems(CO) (*)

### Convex Optimization
#### Definition
- Convex optimization problem: $\min f(x) \quad \text{s.t.} \quad x \in F$
    - Require:
        - objective f is a convex function
            - Value in the middle point is lower than average value.
            $f(tx_{1} + (1-t)x_{2}) <= tf(x_{1}) + (1-t)f(x_{2})$
            if $x_{1}, x_{2} \in F, and t \in [0,1]$
            - 二阶导数>0, 函数先下降后增加
        - feasible region F is a cnvex set
            - A set $C \subset \mathbb{R}^{n}$ is convex is for $x, y \in C$ and any $\alpha \in [0, 1]$, we have:
            $\alpha x + (1-\alpha) y \in C$
            - convex set means any convex combination of two points in the set is also in the set.
    
    - How to determine if a function is convex:
        - Prove by definition
        - User properties
            - 二阶导 > 0: $f^{''}(x) >= 0$
            - Convexity is preserved under a linear transformation
                - if $f(x) = g(Ax + b)$, if g is convex, then f(x) us convex

    - Convex combination
        - 两个点(x, y)连线, 线上的任意一点(z)都叫做convex combination。
        - 数学表达式： Given $x, y \in \mathbb{R}^{n}$ and any $\alpha \in [0, 1]$, the convex combination is: $\alpha x + (1-\alpha) y$

### Concave function (凹函数)
- 定义与Convex function相反(A function is concave is -f is convex)
- Examples:
    - Affine(仿射函数): $f(x) = A^{T}x + b$ where $A \in \mathcal{R}^{n}, b \in \mathcal{R}$
        - 如果一个函数f既是convex function 也是 concave function in $\mathcal{R}^{n}$, 那么f一定是affine function
        - An affine function is a linear function plus a translation/offset
    - Powers: $x^{a}$ where x > 0, 0 <= a <= 1
    - Logarithm: $log{x}$ where x > 0

- convex optimization problem是求最小化 => concave function是求最大化
- 除了Affine function、一些复杂函数也可以既是convex function，也可以是concave function

### In Convex optimization, local optima = global optima
- How to solve convex optimization problems?
    - Gradient
        - 有用的求导方法
            - Linear functions: $f(x) = Ax$
                => $f^{'}(x) = A$
            - Exponents: $f(x) = Ax^{n}$
                => $f^{'}(x) = nAx^{n-1}$
            - Logarithms: $f(x) = Alog{x}$
                => $f^{'}(x) = \frac{A}{x}$
            - 分数: $f(x) = \frac{g(x)}{h(x)}$
                => $f^{'}(x) = \frac{g^{'}(x)*h(x) - g(x)*h^{'}(x)}{h(x)^{2}}$
    - Gradient Descent
        - Initialize: the weights $\theta$ randomly
        - Calculate the gradients: $G$ of loss/cost function $L(\theta)$
        - Update the weights: $\theta = \theta - \alpha * G$
        - Repeat until the $L(\theta)$ stops reducing
    - Step Size
        - Fixed step size: 学习率过大会导致收敛不好，学习率小会导致收敛慢
        - Backtracking line search:
            - Fix a parameter $0 < \beta < 1$, then at each iteration, start with $\alpha = 1$, and while:
                $f(\theta) - f\left(\theta - \nabla_{\theta} f(\theta)\right) \leq \frac{\alpha}{2} \left\| \nabla_{\theta} f(\theta) \right\|^2$ 
            update $\alpha = \beta\alpha$
            - Shrinking stops if the objective function can decrease as expected.

### Lagrange Multiplier (拉格朗日乘数)
- Giving an optimization problem
    - Equality constraints
    $$
    \min_{x} f(x)\\
    \text{s.t. } h_{j}(x) = 0
    $$

- Lagrangian function form:
$$
L(x, \lambda) = f(x) + \sum_j \lambda_j h_j(x)
$$

- Stationary point conditions for equality constraint:
$$
\frac{\partial L}{\partial x_i} = \frac{\partial f}{\partial x_i} + \sum_j \lambda_j \frac{\partial h_j}{\partial x_i} = 0 \quad \frac{\partial L}{\partial \lambda_j} = h_j = 0
$$