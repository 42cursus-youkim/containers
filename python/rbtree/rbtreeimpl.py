from typing import Any, Generic, Iterator

from graphviz import Digraph, nohtml

from .node import Node, NodeColor, T


class RBTree(Generic[T]):
    """
    1. Each node is either red or black.
    2. Root node must be black.
    3. All leaves must be black.
    4. Red nodes must have black children.
    5. Every path from a node to a descendant leaf contains the same number of black nodes.
    """

    def __init__(self, value: T) -> None:
        self.root = Node(value, NodeColor.BLACK)

    def __iter__(self) -> Iterator[Node]:
        yield from self.root.in_order()

    def __len__(self) -> int:
        return sum(1 for node in self if not node.is_nil)

    def _repr_svg_(self) -> str:
        "repr to Jupyter Notebook"
        return self.__graphviz()._repr_image_svg_xml()

    def __graphviz(self, *args: Any, **kwargs: Any) -> Digraph:
        def style(color: str):
            return {"color": color, "fillcolor": color}

        if "node_attr" not in kwargs:
            kwargs["node_attr"] = {
                "shape": "record",
                "style": "filled, rounded",
                "fontname": "Hack",
                "fontpath": "../asset/",
                "fontcolor": "white",
            }

        styles = {
            NodeColor.RED: style("coral2"),
            NodeColor.BLACK: style("black"),
            NodeColor.NIL: style("gray16")
            | {
                "fixedsize": "true",
                "width": "0.5",
                "height": "0.3",
                "magin": "0,0",
                "fontsize": "8",
            },
        }

        digraph = Digraph(*args, **kwargs)

        for node in self:
            node_id = str(id(node))
            digraph.node(
                node_id,
                nohtml(f"<l>|<v> {node.value}|<r>"),
                **styles[node.color],
            )

            if not node.is_nil:
                digraph.edge(f"{node_id}:l", f"{id(node.left)}:v")
                digraph.edge(f"{node_id}:r", f"{id(node.right)}:v")

        return digraph

    @staticmethod
    def recolor(node: Node[T], uncle: Node[T]) -> None:
        print(f"{node.value = }")
        node.parent.color = NodeColor.BLACK  # type: ignore FIXME
        uncle.color = NodeColor.BLACK
        # parent.parent.color = NodeColor.RED

    @staticmethod
    def restructure(node: Node[T]) -> None:
        ...

    def insert(self, value: T) -> None:
        from time import sleep
        def naive_insert(parent: Node[T], node: Node[T]) -> tuple[Node[T], Node[T]]:
            "returns (inserted node, uncle node)"
            if node <= parent:
                parent.left = node
                return parent.left, parent.right
            else:
                parent.right = node
                return parent.right, parent.left

        node = Node(value, color=NodeColor.RED)
        parent = self.root.walk(node)
        inserted, uncle = naive_insert(parent, node)
        print(f"{inserted.value = } {uncle.value = }")
        if uncle.is_black:
            ...
            # self.restructure()
        else:
            print(f'{uncle.value = }')
            print("recolor!")
            sleep(1)
            self.recolor(inserted, uncle)
        print(parent, parent.is_double_red())
        # self.root.insert(node)
