/*
 * Copyright (c) 2024, Tim Flynn <trflynn89@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Forward.h>
#include <LibWeb/Bindings/PlatformObject.h>

namespace Web::HTML {

// https://html.spec.whatwg.org/multipage/dnd.html#the-datatransferitemlist-interface
class DataTransferItemList : public Bindings::PlatformObject {
    WEB_PLATFORM_OBJECT(DataTransferItemList, Bindings::PlatformObject);
    JS_DECLARE_ALLOCATOR(DataTransferItemList);

public:
    static JS::NonnullGCPtr<DataTransferItemList> create(JS::Realm&, JS::NonnullGCPtr<DataTransfer>);
    virtual ~DataTransferItemList() override;

private:
    DataTransferItemList(JS::Realm&, JS::NonnullGCPtr<DataTransfer>);

    virtual void initialize(JS::Realm&) override;
    virtual void visit_edges(JS::Cell::Visitor&) override;

    JS::NonnullGCPtr<DataTransfer> m_data_transfer;
};

}