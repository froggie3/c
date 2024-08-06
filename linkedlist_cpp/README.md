# これは何？

C++ による双方向連結リストの実装。

ポインタをあまり触ったことがなかったのでアルゴリズムや言語の仕様を含めて勉強になった。


## 実装したもの

- `DoublyLinkedList.append(v)`
  - 要素 v をリストの一番後ろに挿入
- `DoublyLinkedList.appendleft(v)`
  - 要素 v をリストの先頭に挿入
- `DoublyLinkedList.remove(v)`
  - 要素 v をリストを辿って検索して削除
- `DoublyLinkedList.pop()`
  - リストの先頭にある要素を削除して取得
- `DoublyLinkedList.popleft()`
  - リストの一番後ろにある要素を削除して取得
- `DoublyLinkedList.get(index)`
  - リストの index 番目にある要素を取得
- `DoublyLinkedList.size()`
  - リスト内の要素を取得