//
//  DemoViewController.swift
//  Demo
//
//  Created by Alex Usbergo on 07/08/15.
//  Copyright © 2015 Alex Usbergo. All rights reserved.
//

import UIKit
import ReflektorKitSwift

class DemoContainerView : UILabel {

}

class DemoViewController: UIViewController {
    
    private var constraints = [NSLayoutConstraint]()
    private let containerView = DemoContainerView(frame:  CGRect.zero, useAppearanceProxy: true)

    override func viewDidLoad() {
        
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        self.containerView.translatesAutoresizingMaskIntoConstraints = false        
        self.view.addSubview(self.containerView)
        
        self.updateViewConstraints()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func traitCollectionDidChange(previousTraitCollection: UITraitCollection?) {
       self.refl_applyStyleToViewRecursive()
    }
    
    override func viewDidLayoutSubviews() {
        self.refl_applyStyleToViewRecursive(true)
    }
    
    override func updateViewConstraints() {
        super.updateViewConstraints()
        
        NSLayoutConstraint.deactivateConstraints(self.constraints)
        self.constraints = self.containerView.refl_appearanceProxy.constraints;
        NSLayoutConstraint.activateConstraints(self.containerView.refl_appearanceProxy.constraints)
    }

    
}
