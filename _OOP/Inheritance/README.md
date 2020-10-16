## 繼承關係
- 被繼承的類別
    - 「父類別」（Parent class）或「基底類別」（Base class）
- 繼承父類別的類別
    - 「子類別」（Child class）或「衍生類別」（Derived class）
- 子類別可以直接取用父類別中的成員
    - public 可以
    - private 不行  (需透過父類別的 public function 來存取或修改)
    - protected 可以 （若想給子類別直接用，又不想給外界用就用 protected）
- Override: 將基底類別的函數重新定義一次 (函數名稱、回傳值及參數均相同) 

## 繼承優點
- 類別再使用(程式碼再使用) code reuse
- 抽象化概念再使用 abstraction reuse
- 類別關係階層化 class hierarchy

## 描述物件之間的關係
- "has-a" -> member data
    - e.g., Each person has a name
    - person.name = "David"
- "is-a-kind-of" -> inheritance
    - e.g., 人是一種動物
    - class Person: public Animal{...};

## 繼承種類
- Public Inheritance: 
    - 父類別 private -> 子類別 不繼承
    - 父類別 protected -> 子類別 protected 
    - 父類別 public -> 子類別 public
- Protected Inheritance: 
    - 父類別 private -> 子類別 不繼承
    - 父類別 protected -> 子類別 protected
    - 父類別 public -> 子類別 protected
- Private Inheritance: 
    - 父類別 private -> 子類別 不繼承
    - 父類別 protected -> 子類別 private
    - 父類別 public -> 子類別 private

