<div class="container container-offset" class="<?php print $classes; ?>"<?php print $attributes; ?>>
            
            
            <div class="row toprow">
                <div class="container topwrapper">
                    
                <div class="six columns">
                  <?php $theme_path = drupal_get_path('theme', variable_get('theme_default', NULL)); ?>
                  <?php $logo_path = $theme_path . "/images/logo.jpg"; ?>
                    <a rel="home" href="<?php print $front_page; ?>"><img src="<?php print $logo_path; ?>"/></a>
                </div>
                  
                <div class="six columns">
                  
                    <div class="row">
                        <div class="twelve columns">
                           
                          <?php if ($page['header']): ?>
                              <?php print render($page['header']); ?>
                          <?php endif; ?>
                          
                        </div>
                    </div>
                </div>
                    
               </div><!-- /wrapper -->
                     
            </div>
                
            
            <div class="row main">
                <div class="twelve columns">
                    
                  <div class="two columns leftcolumn">
                    <div id="primary-nav" class="menu <?php if (!empty($main_menu)) {print "with-primary";} if (!empty($secondary_menu)) {print " with-secondary";} ?>">
                      <?php //print theme('links', array('links' => $main_menu, 'attributes' => array('id' => 'primary', 'class' => array('links', 'clearfix', 'main-menu')))); ?>
                    </div>
                    
                    <?php print render($page['sidebar_first']); ?>
         
                    
                  </div>
                  
                  
                  <div class="seven columns middlecolumn">
                    
                    
                    <?php if ($breadcrumb || $title|| $messages || $tabs || $action_links): ?>
                      <div id="content-header">

                        <?php print $breadcrumb; ?>

                        <?php if ($page['highlight']): ?>
                          <div id="highlight"><?php print render($page['highlight']) ?></div>
                        <?php endif; ?>

                        <?php if ($title): ?>
                          <h1 class="title"><?php print $title; ?></h1>
                        <?php endif; ?>

                        <?php print $messages; ?>
                        <?php print render($page['help']); ?>

                        <?php if ($tabs): ?>
                          <div class="tabs"><?php print render($tabs); ?></div>
                        <?php endif; ?>

                        <?php if ($action_links): ?>
                          <ul class="action-links"><?php print render($action_links); ?></ul>
                        <?php endif; ?>

                      </div> <!-- /#content-header -->
                    <?php endif; ?>
                      
                      <div id="content-area">
                        <?php //print render($page['content']) ?>
                      </div>
                    
                      <?php print views_embed_view("front_page_picture", "block"); ?>
                  </div>
                  
                  
                  <div class="three columns rightcolumn">
                    <?php print render($page['sidebar_second']); ?>
                    
                    
                    
                    
                    
                    
                    
                    
                  </div>
                  
                 
                </div>
            
            </div><!-- /.row.main -->
        
        </div><!-- /container -->
        <div class="container">
          <?php if ($page['footer']): ?>
            <div id="footer">
              <?php print render($page['footer']); ?>
            </div> <!-- /footer -->
          <?php endif; ?>
        </div>