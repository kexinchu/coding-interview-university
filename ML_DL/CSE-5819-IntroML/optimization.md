# Optimization

### Definition
- Optimization problems
    - determine value of optimization variable within feasible region/set to optimize optimization objective
    $$
    \min f(x) \quad \text{s.t.} \quad x \in F
    $$

    -  Optimization variable  $ x \in \mathbb{R}^{n} $
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

- Example
    - Simple functions
        - Convex function: 凸函数
        - Linear funtion
    - Complicated functions
        - Even can be implicitly represented throuogh an algorithm which takes $x \in \mathcal{F}$ as input, and outputs a value

##### Optimization is at the heart of many machine learning algorithms
- MLE: maximum likelihood estimation 最大似然估计
- Linear regression
- Classification (logical regression or SVM)
- K-means clustering