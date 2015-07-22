package LinkedListScala {

class Node[T](var e: T = T(0), var n: Node[T] = null, var a: Node[T] = null) {

  protected _elem: T = e;
  protected _next: Node[T] = n;
  protected _arb: Node[T] = a;
}
}
