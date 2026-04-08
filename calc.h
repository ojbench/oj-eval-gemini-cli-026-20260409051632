#pragma once

#include "visitor.h"
#include <any>

struct calculator : visitor {
    std::any visit_num(num_node *node) override {
        return node->number;
    }

    std::any visit_add(add_node *node) override {
        auto l = visit(node->lnode);
        auto r = visit(node->rnode);
        if (l.type() == typeid(long long)) {
            return std::any_cast<long long>(l) + std::any_cast<long long>(r);
        } else {
            return std::any_cast<double>(l) + std::any_cast<double>(r);
        }
    }

    std::any visit_sub(sub_node *node) override {
        auto l = visit(node->lnode);
        auto r = visit(node->rnode);
        if (l.type() == typeid(long long)) {
            return std::any_cast<long long>(l) - std::any_cast<long long>(r);
        } else {
            return std::any_cast<double>(l) - std::any_cast<double>(r);
        }
    }

    std::any visit_mul(mul_node *node) override {
        auto l = visit(node->lnode);
        auto r = visit(node->rnode);
        if (l.type() == typeid(long long)) {
            return std::any_cast<long long>(l) * std::any_cast<long long>(r);
        } else {
            return std::any_cast<double>(l) * std::any_cast<double>(r);
        }
    }

    std::any visit_div(div_node *node) override {
        auto l = visit(node->lnode);
        auto r = visit(node->rnode);
        if (l.type() == typeid(long long)) {
            return std::any_cast<long long>(l) / std::any_cast<long long>(r);
        } else {
            return std::any_cast<double>(l) / std::any_cast<double>(r);
        }
    }

    ~calculator() override = default;
};