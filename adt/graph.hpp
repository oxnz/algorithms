//
//  graph.hpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/14.
//  Copyright © 2019 云心逸. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <vector>
#include <unordered_set>

namespace graph {
	template <typename T>
	struct Node {
	private:
		using adjaceny_list_type = std::unordered_set<size_t>;
		adjaceny_list_type& get_adjacent_node_indices() { return m_adjacent_node_indices; }
		const adjaceny_list_type& get_adjacent_node_indices() const { return m_adjacent_node_indices; }
		T m_data;
		adjaceny_list_type m_adjacent_node_indices;
	public:
		explicit Node(const T& v) : m_data(v) {}
		explicit Node(T&& v) : m_data(std::move(v)) {}
		T& get() noexcept { return m_data; }
		const T& get() const noexcept { return m_data; }
		bool operator==(const Node& rhs) const { return m_data == rhs.m_data && m_adjacent_node_indices == rhs.m_adjacent_node_indices; }
		bool operator!=(const Node& rhs) const { return !operator==(rhs); }
		void swap(Node& rhs) noexcept {
			std::swap(m_data, rhs.m_data);
			std::swap(m_adjacent_node_indices, rhs.m_adjacent_node_indices);
		}
	};

	template <typename T>
	class directed_graph {
	private:
		using node_container_type = std::vector<Node<T>>;
		node_container_type m_nodes;
		typename node_container_type::iterator find(const T& val) {
			return std::find_if(std::begin(m_nodes), std::end(m_nodes), [&val](const Node<T>& node) {
				return node.get() == val;
			});
		}
		typename node_container_type::const_iterator find(const T& val) const {
			return const_cast<directed_graph<T>*>(this)->find(val);
		}
		void remove_all_links_to(typename node_container_type::const_iterator node);
		std::unordered_set<T> get_adjancent_node_values(const typename Node<T>::adjanceny_list_type& indices) const {
			std::unordered_set<T> values;
			for (auto&& index : indices) values.insert(m_nodes[index].get());
			return values;
		}
	};
}

#endif /* graph_hpp */
