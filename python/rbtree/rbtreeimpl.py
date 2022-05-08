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

    def insert(self, value: T) -> None:
        node = Node(value, color=NodeColor.RED)
        self.root.insert(node)

    def _repr_svg_(self) -> str:
        "repr to Jupyter Notebook"
        return self.graphviz()._repr_image_svg_xml()

    def graphviz(self, *args: Any, **kwargs: Any) -> Digraph:
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
