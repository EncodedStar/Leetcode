# 《offer来了》设计模式篇--抽象工厂模式
----

**抽象工厂模式（Abstract Factory Pattern）**
在工厂模式上添加了一个创建不同工厂的抽象接口（抽象类或接口实现），该接口可叫作超级工厂。在使用过程中，我们首先通过抽象接口创建出不同的工厂对象，然后根据不同的工厂对象创建不同的对象。

我们可以将工厂模式理解为针对一个产品维度进行分类，比如苹果或华为公司生产多个产品（手机、电脑、etc..）

在同一个厂商有多个维度的产品时，如果使用工厂模式，则势必会存在多个独立的工厂，这样的话，设计和物理世界是不对应的。正确的做法是通过抽象工厂创建出来的工厂类比成不同产品的生产线，在需要生产产品时根据抽象工厂生产。

**区别**

```c++
# 不用设计模式
int main() {
    # 每次增加新需求，就需要添加一个类，改动比较大，重复代码太多
    
    HuaWeiIphone huawei_iphone = new HuaWeiIphone();
    AppleIphone apple_iphone = new AppleIphone();
    
    HuaWeiIpad huawei_ipad = new HuaWeiIpad();
    AppleIpad apple_ipad = new AppleIpad();
}
```

```c++
# 工厂模式
int main() {
    # 将Phone、Ipad 分为2个工厂，每次增加新商品直接添加功能分支，
    # 不会影响之前逻辑，代码简洁而且没有冗余。
    
    PhoneFactory phoneFactory = new PhoneFactory();
    Phone huawei_iphone = phoneFactory.createPhone("HuaWei");
    Phone apple_iphone = phoneFactory.createPhone("Apple");
    
    IpadFactory ipadFactory = new IpadFactory();
    Ipad huawei_ipad = ipadFactory.createIpad("Huawei");
    Ipad apple_ipad = IpadFactory.createIpad("Apple");
}
```

```c++
# 抽象工厂模式
int main() {
    # 将俩个工厂的接口封装起来
    
    AbstractFactory phoneFactory = new PhoneFactory();
    Phone huawei_iphone = phoneFactory.createPhone("HuaWei");
    Phone apple_iphone = phoneFactory.createPhone("Apple");
    
    AbstractFactory ipadFactory = new IpadFactory();
    Ipad huawei_ipad = ipadFactory.createIpad("Huawei");
    Ipad apple_ipad = IpadFactory.createIpad("Apple");
}
```
